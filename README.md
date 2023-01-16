# Demo CLion CTest Configuration Issue

CLion CTest run configurations do not include Environment Variables when debugging.

This is a simple executable `ConfigIssue` which fetches an environment variable `SAMPLE`; the test `DemoConfigIssue` asserts that the environment variable is set to some value.

In more complex cases, such as when `PATH` is modified, this causes the test to fail to launch and so cannot be debugged.

## Steps to reproduce

1. Load this CMake Project
2. ___Run___ the _All CTest_ configuration; the test fails with output `Sample: ''`
3. Edit the _All CTest_ configuration.
4. Set the environment variable: `SAMPLE=VALUE`
5. ___Run___ the _All CTest_ configuration; the test passes with output `Sample: 'VALUE'`
6. ___Debug___ the _All CTest_ configuration; the output will be `Sample: ''`

One would expect the output to be the same whether the test launched via ___Run___ or ___Debug___, since the configuration is unchanged.

Note that setting the environment variables via script also fails, as in `source env.bat`. Where `env.bat` would contain:

```cmd
SET SAMPLE=VALUE
```

## Tested Platforms:

| OS           | CLion    | CMake            | Toolchain          |
|--------------|----------|------------------|--------------------|
| Windows 11   | 2022.3.1 | 3.24.2 (bundled) | Visual Studio 2019 |
| Ubuntu 22.04 | 2022.3.1 | 3.24.2 (bundled) | GCC 11.3           |
