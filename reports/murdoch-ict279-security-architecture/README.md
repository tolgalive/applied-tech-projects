# ICT279: Detection and Mitigation of a CVE

A security architecture project focused on detecting and mitigating a real CVE-class vulnerability (path traversal / unauthorized PUT requests) using Splunk for log monitoring, alerting, and event correlation.

## What it covers

- Setting up detection rules for a path traversal attack and unauthorized file writes (PUT requests)
- Building alerts that trigger on attack patterns while staying quiet on normal traffic
- Correlating multiple security events to escalate to a high-severity alert
- Verifying detections against both attack traffic and normal traffic (to check for false positives)

## Evidence

- `01_PUT_Detection_Script_and_Alert.png` — detection script and resulting alert for an unauthorized PUT request
- `07_Event_Correlation_HIGH_ALERT.png` — correlated events escalating to a high-severity alert

Group project (report co-authored with Posha and Minou), part of a Murdoch University unit, ICT279 Security Architecture and Controls.
