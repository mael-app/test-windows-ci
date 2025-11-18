# hello-windows

This repo contains a minimal C++ console app compiled on Windows, Linux, and macOS runners in GitHub Actions. Each release builds platform-specific artifacts so you can confirm GitHub Actions Windows support alongside Linux packages (`.deb`, `.rpm`, `.tar.gz`) and a macOS binary.

## Project layout

- `src/hello-windows.cpp` – tiny program that prints a confirmation message.
- `.github/workflows/windows-release.yml` – CI pipeline that compiles the app on Windows, Ubuntu, and macOS, packages the outputs, and publishes a release containing every artifact.

## Local build

You can quickly verify the code on macOS/Linux using any C++17 compiler:

```bash
clang++ src/hello-windows.cpp -std=c++17 -o hello-windows
./hello-windows
```

The GitHub workflow performs analogous builds with MSVC, `g++`, and `clang++` to emit artifacts for each OS.

## Releasing

1. Commit and push your changes to `main`.
2. Create and push a tag (for example `git tag v0.1.0 && git push origin v0.1.0`).
	- Alternatively, launch the workflow manually from the **Actions** tab (`Run workflow`) to generate an ad-hoc release; the pipeline will auto-create a tag such as `manual-v<run>` if you leave the inputs blank.
3. The workflow triggers automatically, builds every artifact, and creates a GitHub release attaching them all.

### Release artifacts

Each successful run uploads the following assets under the "Assets" section of the generated release:

| Platform | Artifact(s) |
| --- | --- |
| Windows | `hello-windows-windows.exe` |
| Linux | `hello-windows-linux` (plain binary), `hello-windows-linux.tar.gz`, `hello-windows_<version>_amd64.deb`, `hello-windows-<version>-1.x86_64.rpm` |
| macOS | `hello-windows-macos.zip` (contains the executable) |

Pick the artifact that matches your environment, download it, and run the binary (`chmod +x` on Unix-like systems if needed).
