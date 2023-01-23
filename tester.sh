#!/bin/bash

make > tester.log
echo "ORIGINAL OUTPUT:" > tester.log
< test awk '{print$0}' | grep hallo | wc -l >> tester.log
echo "MY OUTPUT:" >> tester.log
./pipex test 'awk "{print$0}"' "grep hallo" "wc -l" >> tester.log
cat tester.log
