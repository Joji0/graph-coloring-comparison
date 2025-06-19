#!/bin/bash

set -e

echo "📦 Cloning Boost as submodule (if not exists)..."

if [ ! -d "boost" ]; then
  git submodule add --branch boost-1.84.0 https://github.com/boostorg/boost.git data/random/boost
fi

echo "📁 Updating submodules..."
git submodule update --init --recursive

echo "🔧 Bootstrapping Boost headers..."
cd boost

./bootstrap.sh
./b2 headers

echo "✅ Boost setup complete!"
