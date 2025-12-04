# C++ Quant Trading Lab

A modular, event-driven C++ research framework for quant trading and financial experimentation.  
The project focuses on realistic backtesting, performance awareness, and clear systems design.

This repository is structured as a collection of systems that mirror how quantitative research and trading technology is built.

---

## Key Goals

1. Build a clean, extensible C++ foundation for quantitative trading research
2. Avoid common backtesting errors (look-ahead bias, zero-cost execution)
3. Emphasize risk controls and transaction cost modeling
4. Develop performance-aware C++ systems suitable for low-latency  environments
5. Act as a base for future machine learning–driven strategies

---

## Architecture Overview

Market Data
v
Signal Generation
v
Order Creation
v
Execution and Fills
v
Portfolio State
v
Risk Management
v
Performance and Metrics

---

## Design Principles

 - Event-driven architecture
 - Modeling of execution and costs
 - Strategy logic independent of portfolio and execution

## Repository Structure

cpp-quant-trading-lab/
│
├── CMakeLists.txt
├── README.md
│
├── data/ (Sample Datasets - CSV)
│   ├── raw/
│   ├── processed/
│   └── samples/
│
├── include/  (Public Headers and Interfaces)
│   ├── common/
│   ├── market_data/
│   ├── analytics/
│   ├── execution/
│   ├── strategy/
│   ├── risk/
│   └── utils/
│
├── src/ (Core Implementation)
│   ├── market_data/
│   ├── analytics/
│   ├── execution/
│   ├── strategy/
│   ├── risk/
│   └── utils/
│
├── apps/ (Small Command Line Tools)
│   ├── data_tools/ (Data Gathering and Inspection)
│   ├── analytics_tools/ (Metrics and PnL Analysis)
│   ├── backtest/ (Backtest Runners)
│   └── benchmarks/ (Latency and Memory Benchmarks)
│
├── tests/ (Unit Tests)
│   ├── market_data/
│   ├── analytics/
│   ├── execution/
│   └── strategy/
│
├── benchmarks/ (Performance Experiments)
│
├── scripts/
│
└── docs/ (Design Notes and Diagrams)

## Implemented Components

### Market Data
- CSV-based historical market data ingestion
- Timestamp normalization using `std::chrono`
- Order book snapshot representation (Level 1 / Level 2)
- Market microstructure metrics (spread, mid-price, imbalance)

### Analytics
- Log and arithmetic returns
- Rolling window statistics
- Volatility estimation
- Performance metrics (Sharpe, max drawdown)
- Numerical stability considerations

### Execution
- Transaction cost modeling (fixed + percentage costs)
- Slippage models based on trade size
- Realistic fill price modelling

### Strategy & Portfolio
- Event-driven strategy interface
- Signal abstraction
- Portfolio state tracking
- Example systematic strategies (e.g. mean reversion)

### Risk Management
- Position and exposure limits
- Drawdown-based kill switches
- Volatility targeting hooks

### Performance & Systems
- Latency benchmarking tools
- Container and allocation experiments
- Custom memory pool utilities
- Emphasis on cache-friendly data layouts

---

## Example Usage

### Build
```bash
mkdir build
cd build
cmake ..
make -j
