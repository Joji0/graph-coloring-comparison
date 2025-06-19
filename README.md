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

## ▶️ How to Generate Random Graph (Erdős–Rényi)

Follow these steps to compile and run the program for generating random graphs:

### 1. Clone the Repository (with Boost)

Make sure to include the Boost submodule:

```bash
git clone --recurse-submodules https://github.com/Joji0/graph-coloring-comparison.git
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
bash setup_boost.sh
```

### 3. Compile the Generator

Compile the generator:

```bash
g++ -std=c++20 -O2 -Iboost generate_random.cpp -o generate_random
```

### 4. Generate Random Graph (Erdős–Rényi)

Run the generator using:

```bash
./generate_random
```

### 5. 📁 Output

This will create three random graph files in the same folder:

- `random_n50.txt`
- `random_n100.txt`
- `random_n200.txt`

Each file contains:

- The first line: number of vertices and edges (`n m`)
- The next `m` lines: pair of vertex `u` and `v`, which shows that there is an edge between them (1-based indexed)

## ▶️ How to Generate Other Type of Graph

### 1. Navigate to the Data Folder

Navigate to the data/{graph-type}/ folder:

```bash
cd data/{graph-type}
```

### 2. Compile the Generator

Compile the generator:

```bash
g++ -std=c++20 -O2 generate_{graph-type}.cpp -o generate_{graph-type}
```

### 3. Generate Graph Type

Run the generator using:

```bash
./generate_{graph-type}
```

## 📊 How to Benchmark

### 1. Navigate to the Benchmarker Folder

Navigate to the benchmarker/ folder:

```bash
cd benchmarker
```

### 2. Compile the Benchmarker

Compile the benchmarker:

```bash
g++ -std=c++20 -O2 benchmarker_{algorithm}_{graph-type}.cpp -o benchmarker_{algorithm}_{graph-type}
```

### 3. Run the Benchmarker

Run the benchmarker using:

```bash
./benchmarker_{algorithm}_{graph-type}
```
