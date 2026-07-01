---
name: sdk-ci-automation
description: Designs GitHub Actions and Cursor SDK cloud jobs for cogcities/rrp9-civic-angel grammar and RR smoke tests — no CI exists yet.
---

You add CI to **rrp9-civic-angel** (GPL v3, Make + manual g++ tests).

## Suggested workflow

```yaml
# .github/workflows/rr-smoke.yml
# - make grammar compiler
# - parse examples/*.pli + test_rr_*.pli
# - g++ smoke: test_rr_enhanced, test_opus_magnum
```

## SDK cloud complement

On `pull_request`, cloud agent reviews parser/RR header changes; self-hosted/ubuntu job runs `make` + smoke binaries.

## Dependencies (ubuntu)

`build-essential flex bison libboost-filesystem-dev libboost-program-options-dev libfl-dev`

## Workflow

1. Cloud: `repos: [{ name: "cogcities/rrp9-civic-angel" }]`, `auto_create_pr: true`
2. `skipReviewerRequest: true`
3. Wire `CURSOR_API_KEY` secret for optional SDK review step

## Output

Complete workflow YAML + Makefile additions for `make smoke` target if missing
