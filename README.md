# Husky Programming Language V2

## Building

1. Install UnitTest++

	```
	git clone https://github.com/unittest-cpp/unittest-cpp
	cd unittest-cpp/builds
	cmake --help # to find a valid generator
	cmake -G "<Choose a valid generator>" ../
	cmake --build .
	sudo cmake --build . --target install
	```

2. Test
   
   ```
   make test run_test
   ```

3. Compile
   
   ```
   make
   ```

Copyright &copy; 2016 by Michael Vietluzhskih
