# hello-windows

This repo contains a minimal C++ console app compiled on Windows runners in GitHub Actions. Each tagged release automatically builds `hello-windows.exe` and publishes it as a release asset, letting you verify Windows support end-to-end.

## Project layout

- `src/hello-windows.cpp` – tiny program that prints a confirmation message.
- `.github/workflows/windows-release.yml` – CI job that compiles the app on `windows-latest`, uploads the executable, and creates a GitHub release.

## Local build

You can quickly verify the code on macOS/Linux using any C++17 compiler:

```bash
clang++ src/hello-windows.cpp -std=c++17 -o hello-windows
./hello-windows
```

The GitHub workflow performs the analogous build with MSVC to emit `hello-windows.exe`.

## Releasing

1. Commit and push your changes to `main`.
2. Tag the commit (for example `git tag v0.1.0 && git push origin v0.1.0`).
3. The workflow triggers automatically, builds the executable on Windows, and creates a release attaching `hello-windows.exe`.

You'll find the compiled binary under the "Assets" section of the generated release.
