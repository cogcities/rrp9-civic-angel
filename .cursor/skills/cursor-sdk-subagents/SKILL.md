---
name: cursor-sdk-subagents
description: Creates Cursor SDK subagents for cogcities/rrp9-civic-angel (RR-PLingua, P-systems, Relevance Realization, Civic Angel/Opus Magnum Civitas). Use when automating grammar regression, RR smoke tests, or plingua→psim pipeline checks for this repo.
---

# Cursor SDK Subagents — rrp9-civic-angel

Repo: **cogcities/rrp9-civic-angel** · RR-PLingua · C++11 · Flex/Bison · Make · GPL v3 · no in-repo CI.

Compose **subagent authoring** with **SDK domain knowledge** — read `/sdk` for API truth; use this skill for repo-specific subagent design.

## Repo context

| Area | Paths |
|------|-------|
| Parser | `src/parser/plingua.l`, `src/parser/plingua.y` (RR tokens) |
| Build | `Makefile` → `bin/plingua`, `bin/psim` |
| RR core | `include/relevance_realization.hpp` |
| AtomSpace / PLN | `include/atomspace_integration.hpp`, `pln_integration.hpp`, `persistent_atomspace.hpp` |
| Civic Angel | `include/civic_angel.hpp` — 253-agent Opus Magnum Civitas |
| Examples | `examples/*.pli`, `test_rr_enhanced.pli` |
| Manual tests | `test_rr_enhanced.cpp`, `test_civic_integration.cpp`, `test_opus_magnum.cpp` |
| Docs | `docs/`, `OPUS_MAGNUM_CIVITAS_IMPLEMENTATION.md` |

**Pipeline:** `.pli` → `bin/plingua` → `.psb`/generated `.cpp` → `bin/psim`. RR/civic tests compiled manually with `g++ -I./include -std=c++11`.

## SDK runtime choice for this repo

| Task | Runtime | Why |
|------|---------|-----|
| Grammar regression, doc sync, civic invariant review | **Cloud** `repos: [{ name: "cogcities/rrp9-civic-angel" }]` | Edits source, opens PRs |
| `make all` + run `test_opus_magnum` locally | **Local** `cwd: .` | Needs flex, bison, boost on caller machine |

Cloud agents should scaffold CI (Makefile targets for smoke tests) when asked — repo has no workflows yet.

## Installed subagents

| Subagent | Use when |
|----------|----------|
| [plingua-grammar-guard](../../agents/plingua-grammar-guard.md) | Flex/Bison or RR `.pli` fixture changes |
| [rr-smoke-runner](../../agents/rr-smoke-runner.md) | Manual integration binaries and thresholds |
| [civic-civitas-sim](../../agents/civic-civitas-sim.md) | 253-agent hierarchy and alchemical stage invariants |

## Templates

- [sdk-integration-builder.md](templates/sdk-integration-builder.md) — cloud agent for RR integration scaffolding
- [sdk-ci-automation.md](templates/sdk-ci-automation.md) — add GitHub Actions for grammar + smoke tests
- [sdk-run-debugger.md](templates/sdk-run-debugger.md) — debug SDK jobs targeting this repo
- [plingua-grammar-guard.md](templates/plingua-grammar-guard.md) — subagent source template

## Example cloud prompt (grammar regression PR)

```typescript
await Agent.prompt(
  "After plingua.y RR token changes, verify all examples/*.pli and test_rr_*.pli parse via make grammar compiler, " +
  "and add a GitHub Actions workflow to run grammar + test_rr_enhanced smoke on PRs.",
  {
    apiKey: process.env.CURSOR_API_KEY!,
    model: { id: "composer-2.5" },
    cloud: {
      repos: [{ name: "cogcities/rrp9-civic-angel", branch: "master" }],
      autoCreatePR: true,
    },
    skipReviewerRequest: true,
  },
);
```

## Creation workflow

```
- [ ] Pick subagent purpose (grammar / RR dynamics / AtomSpace / civic / pipeline)
- [ ] Place in .cursor/agents/<name>.md
- [ ] Reference Makefile targets and manual g++ invocations from README
- [ ] Test: "Use the <name> subagent to …"
```

## SDK traps

Runtime explicit · disposal · `wait()` · `CursorAgentError` vs `status === "error"` · MCP re-pass on resume.

Docs: [TypeScript SDK](https://cursor.com/docs/sdk/typescript) · [Python SDK](https://cursor.com/docs/sdk/python)
