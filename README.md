# Pluto
Pluto Engine

## Logging
Pluto Engine uses spdlog as its logging library. Pluto Engine has two different loggers: Core, and Client. The Core logger is only meant to be used from within the engine itself, whereas the Client logger is meant for applications using the Pluto Engine.

### Macros
Pluto Engine exposes macros for logging.

#### Core
For the Core logger, the following macros are available:
- `PLUTO_CORE_TRACE`
- `PLUTO_CORE_INFO`
- `PLUTO_CORE_WARN`
- `PLUTO_CORE_ERROR`
- `PLUTO_CORE_CRIT`

#### Client
For the Client logger, the following macros are available:
- `PLUTO_TRACE`
- `PLUTO_INFO`
- `PLUTO_WARN`
- `PLUTO_ERROR`
- `PLUTO_CRIT_`
