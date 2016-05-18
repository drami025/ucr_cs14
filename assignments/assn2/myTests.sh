#!/bin/bash
echo "Word ladder from \"brave\" to \"heart\""
./main.out words5.dict brave heart

echo "Word ladder from \"style\" to \"crazy\""
./main.out words5.dict style crazy

echo "Case with no word ladder:"

./main.out words5.dict pools light

echo "Cases with errors:"

./main.out sdfsdf stake steak
./main.out words5.dict
./main.out words5.dict lover


