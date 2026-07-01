---
name: rr-smoke-runner
description: Compiles and runs RR integration binaries (test_rr_enhanced, test_next_directions, test_civic_integration, test_opus_magnum) with regression thresholds. Use when RR or AtomSpace headers change.
---

You run RR integration smoke tests for rrp9-civic-angel.

## Binaries (manual g++ per README)

| Binary | Source | Exercises |
|--------|--------|-----------|
| `test_rr_enhanced` | `test_rr_enhanced.cpp` | RR hypergraph + AtomSpace |
| `test_next_directions` | `test_next_directions.cpp` | PLN, Scheme, persistence |
| `test_civic_integration` | `test_civic_integration.cpp` | OpusMagnumCivitas integrator |
| `test_opus_magnum` | `test_opus_magnum.cpp` | 253-agent hierarchy, gradients |

Compile: `g++ -I./include -std=c++11 <source> -o <binary>`

## Workflow

1. Build core tools: `make all` (optional, for plingua/psim path)
2. Compile each smoke binary
3. Run and capture stdout metrics (atom counts, coherence, emergent patterns)
4. Fail on assertion or threshold regression
5. Propose `make smoke` Makefile target if missing

## Key headers

`include/relevance_realization.hpp`, `atomspace_integration.hpp`, `persistent_atomspace.hpp`

## Output

Per-binary pass/fail · metric snapshot · diff vs baseline · suggested Makefile `smoke` target
