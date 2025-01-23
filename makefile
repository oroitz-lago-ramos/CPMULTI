all: 
	@echo "Checking if build directory exists..."
	@if [ ! -d "build" ]; then \
		echo "Directory 'build' does not exist. Creating..."; \
		mkdir build; \
	fi
	cmake -S . -B build
	make -C build

run:
	build/OpenCVTest
