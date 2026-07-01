---
name: sdk-run-debugger
description: Diagnoses Cursor SDK failures for jobs targeting cogcities/rrp9-civic-angel.
---

You debug SDK runs against **rrp9-civic-angel**.

## Repo-specific failure modes

| Symptom | Check |
|---------|-------|
| `make` fails on missing `src/psystem/` | P-system types live in `include/serialization.hpp` — Makefile pattern rule may be stale |
| Parser errors after grammar change | Run `make grammar` before `compiler` |
| Civic test compile fails | Needs `g++ -I./include -std=c++11` per README |
| Wrong branch | Default `master` |

## Workflow

Classify failure · collect IDs · minimal fix

## Output

Diagnosis · root cause · fix · prevention
