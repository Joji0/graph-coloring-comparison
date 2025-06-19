# Graph Coloring Comparison

This repository contains C++ implementations and benchmarking tools for analyzing the performance of three classic graph coloring algorithms:

- **Backtracking**
- **Basic Greedy**
- **DSatur (Degree of Saturation)**

The experiments were conducted as part of an academic study comparing these algorithms across a variety of synthetic graph instances, including:

- Erdős–Rényi (Random) Graphs
- Grid Graphs
- Bipartite Graphs
- Complete Graphs
- Crown Graphs

## 🔧 Environment

All programs were written in **C++20** and compiled using the **GNU Compiler Collection (g++)** with optimization flag `-O2`. Benchmarks were conducted on a **MacBook Pro (Apple Silicon M4, 16GB RAM)**.

## ▶️ How to Run (Step by Step)

Follow these steps to compile and run the program for generating random graphs:

### 1. Clone the Repository (with Boost)

Make sure to include the Boost submodule:

```bash
git clone --recurse-submodules https://github.com/your-username/graph-coloring-comparison.git
cd graph-coloring-comparison
```

If you’ve already cloned the repository before:

```bash
git submodule update --init --recursive
```

### 2. Set Up Boost

Navigate to the data/random/ folder and run the setup script:

```bash
cd data/random
./setup_boost.sh
```

### 3. Compile the Generator

```bash
g++ -std=c++20 -O2 -Iboost generate_random.cpp -o generate_random
```

### 4. Generate Random Graph (Erdős–Rényi)

Run

```bash
./generate_random
```
