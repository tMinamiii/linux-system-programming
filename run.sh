#!/bin/bash

docker run -it linux-system-programming_sandbox  /bin/bash -c 'cd /root; exec "${SHELL:-sh}"'
