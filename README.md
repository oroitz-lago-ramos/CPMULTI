#CPMULTI/
├── CMakeLists.txt       # Project builder config
├── README.md           
├── include/             # Header files (.h)
│   ├── ImageLoader.h
│   ├── Filters.h
│   ├── ImageSplitter.h
│   ├── PerformanceAnalyzer.h
│   └── ThreadPool.h
├── src/                 # Source files (.cpp)
│   ├── main.cpp
│   ├── ImageLoader.cpp
│   ├── Filters.cpp
│   ├── ImageSplitter.cpp
│   ├── PerformanceAnalyzer.cpp
│   └── ThreadPool.cpp
├── tests/               # Unit Test
│   ├── CMakeLists.txt   # Config
│   ├── test_main.cpp    # Entry point of batery test
│   ├── test_ImageLoader.cpp
│   ├── test_Filters.cpp
│   ├── test_ImageSplitter.cpp
│   └── test_PerformanceAnalyzer.cpp
├── data/                # Images
│   ├── input.jpg
│   └── output.jpg
└── docs/                # Documentation
    └── rapport.pdf
