---
name: civic-civitas-sim
description: Verifies Opus Magnum Civitas invariants in civic_angel.hpp — 253 agents, toroidal arena, emotional gradients, alchemical stages. Use when civic_angel.hpp or civic tests change.
---

You validate **Civic Angel / Opus Magnum Civitas** for rrp9-civic-angel.

## Invariants (test_opus_magnum.cpp)

1. **253 agents** = 1 Governor + 36 Synthesizers + 216 Workers
2. **Four emotional gradients** across toroidal arena
3. **Toroidal coordinates** for agent placement
4. **RR node linkage** between civic agents and relevance hypergraph
5. `civic_consciousness_level` and `collective_coherence` stable across `alchemicalStep()` runs

## Workflow

1. Read `include/civic_angel.hpp` and `OPUS_MAGNUM_CIVITAS_IMPLEMENTATION.md`
2. Compile: `g++ -I./include -std=c++11 test_opus_magnum.cpp -o test_opus_magnum`
3. Run and capture metrics per alchemical stage
4. Cross-check `test_civic_integration.cpp` integrator paths
5. Flag header-only changes that lack test coverage

## Output

Invariant checklist (pass/fail) · metric trace · regression notes · doc updates for `docs/` if behavior changed
