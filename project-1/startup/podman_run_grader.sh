#!/bin/bash

# Docker command to run the grader
podman run --rm -v "$(pwd)":/grading_dir -w /grading_dir -v "$(pwd)"/tests/testcases:/grading_dir/tests/testcases -v "$(pwd)"/tests/extra:/grading_dir/tests/extra -v "$(pwd)"/tests/input:/grading_dir/tests/input -v "$(pwd)"/tests/output:/grading_dir/tests/output arblock/autograder  /bin/bash -c "autograder run"
