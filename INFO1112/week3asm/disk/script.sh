#!/bin/bash

# YOUR CODE HERE
df | tail +2 | sort -r -k 3 -n  | cut -d " "  -f 1