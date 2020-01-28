# search-server
This [project](https://github.com/idoze2/search-server/) was written as part of the Advanced Programming 1 Course (89210), BIU.

## Dependencies
- g++
```bash
sudo apt install g++
```

<b>Optional:</b>
```bash
sudo apt install make
```
## Usage:
Note: must be used on a unix machine.
```bash
make <APP> (OPTIONAL: File=<Fly.txt Path> )
```

<b>Available apps:</b>
- lexer
- parser
- main

<b>To compile-only any app:</b>
 ```bash
 make <APP>.out
 ```

### Additional Makefile Commands
<b>run the simulator:</b>

(note, you have you have flightgear installed for this)

Edit your path in the make, or use with argument FG_PATH=<PATH>.

```bash
make run_simulator <optionally FG_PATH>
```
optionally, you can run a minimalised version of the simulator, with flags specified in Project_Data/flags_mini.txt:
```bash
make run_simulator_mini <optionally FG_PATH>
```

<b>copy generic.xml file to the required flightgear folder.</b>
```bash
make copy_protocol <optionally FG_PATH>
```

<b>run a server with the winning algorithm (BFS)</b>
```bash
make run
```

### Benchmark
The results shows that BFS is the most node-efficient, as seen here:
![result1](project_data/result1.png)
and zoomed:
![result1](project_data/result_zoomed.png)
Compiles and runs 4 instances of each algorithm, Conducting an empirical experiment and summing the results in benchmark/results.png
```bash
sudo apt install python3
make benchmark
```
BIU © [Ido Zeira](http://github.com/idoze2), [Allen Bronshtein](http://github.com/allenbronshtein)
