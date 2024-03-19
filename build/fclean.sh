#!/bin/sh

set -e

cd "$(dirname "$0")/.."

sh build/clean.sh
rm -f libmb_colorizer_basic.a
