# Running the Autograder
You may choose to run the provided autograder to get an idea of how your code will perform when I run the autograder.
This readme contains instructions for setting up and running the autograder.

**Important**: this is optional and not required for you to do your project.
As such, I will provide limited support if you run into issues running the Autograder.

## Setting up the Autograder
The provided `Dockerfile` will be used to build the autograder image.
It appears at the root directory of this repository; see the below screenshot.
We will use this `Dockerfile` to build the autograder image.

![Screenshot of root directory structure of this repository.](./root-dir-struct.png)

### Method 1: Docker Desktop
If you are running Windows or macOS, this is the recommended way to install Docker.
1. Download and install [Docker Desktop](https://www.docker.com/products/docker-desktop/) for your machine.
    - [Instructions for macOS](https://docs.docker.com/desktop/setup/install/mac-install/)
    - [Instructions for Windows](https://docs.docker.com/desktop/setup/install/windows-install/)
    - [Instructions for Linux](https://docs.docker.com/desktop/setup/install/linux/)

2. Run Docker Desktop.
You should be met with something like the screenshot below.
![Screenshot of Docker Desktop.](docker-desktop.png)

3. Now, you will need to build the image.
On macOS, you will need to use the command line.
For Windows, I am not sure, but you should be able to use the command line to do this as well.

Navigate to the directory above where the `Dockerfile` lives.
Run the following command:

```
docker buildx build -t arblock/autograder:latest .
```

This will automatically build the Docker image correctly for your specified platform (e.g., x86, arm64).


### Method 2: Podman Desktop
If you are running Windows or macOS, this is the recommended way to install Podman.
1. Download and install [Podman Desktop](podman-desktop.io).
    - [Instructions for macOS](https://podman-desktop.io/docs/installation/macos-install)
    - [Instructions for Windows](https://podman-desktop.io/docs/installation/windows-install)
    - [Instructions for Linux](https://podman-desktop.io/docs/installation/linux-install)

2. Run Podman Desktop.
You should be met with something like the screenshot below.
![Screenshot of Podman Desktop.](podman-desktop.png)

3. Make sure that the Podman Machine is running.
Click on the bottom left tab labeled "Settings" (with the gear icon in the above screenshot), then clikc "Resources".
See the screenshot below for reference.

![Screenshot of Podman Desktop settings > resources tab.](podman-settings.png)

Click the "Start" button under "Podman Machine" (it is a play button "▶").

4. Now, you will need to build the image.
Podman Desktop makes this easy.
    i. Using the above screenshot as a reference, click the "Images" tab on the left.
    You will see a screen that looks something like the following screenshot.
    ![Screenshot of Podman Desktop images tab.](podman-images.png)

    ii. At the top right corner, click the "Build" button.
    You will see a screen that looks like the following screenshot.
    ![Screenshot of Podman Desktop images > build tab.](podman-build.png)

    iii. Click the folder icon to the right of "Containerfile path" on the first line.
    Here, navigate to where the `Dockerfile` lives in your repository.

    iv. For the "Image Name", enter `arblock/autograder`.

    v. For "Platform", be sure that the correct platform is selected (this should be automatically done).

    vi. Click "Build" at the bottom.

### Other methods
You may attempt to build this image via command line using `docker buildx` or `podman build`.
However, do this at your own discretion. 
While I was able to build the image successfully using `docker` on both my x86 Linux machine and arm64/v8 MacBook Pro, the image failed to run when built via `podman` on my MacBook Pro.

## Setting up your directory structure for the Autograder
If you update the repository, your directory should have the correct structure. 
If not, you need the following directory structure.

- `repository_root/`
    - `Dockerfile`
    - `project-2/`
        - `results/`
        - `startup/`
            - `docker_run_grader.sh`
            - `podman_run_grader.sh`
        - `tests/`
            - `config.toml`
            - `extra/`
            - `testcases/`

Important to add are the `results`, `startup`, and `tests` directories with the appropriate structure.
Inside `startup`, there are two scripts, each one is to run the Autograder using either Docker or Podman (depending on how you set up the Autograder).
Inside `tests`, there is a `config.toml` file which controls how the Autograder runs testcases, including the weight of each test case, the total number of points, etc.
Inside `testcases`, there are `.cpp` files which will test your code.
Finally, `results` is where the Autograder will output your test results.

## Running the Autograder
Running the Autograder is simple.
From the `project-2` directory, run `./startup/docker_run_grader.sh` or `./startup.podman_run_grader.sh`, depending on if you built the Autograder with Docker or Podman.
It is important that you do not `cd` into the `startup` directory and run the Autograder from there; you must run it from the `project-2` directory for the provided scripts to work properly.


## Writing more test cases for the Autograder
See [the Autograder documentation](https://zmievsa.github.io/autograder/#/?id=writing-testcases) for how to write test cases.
The [GitHub](https://github.com/zmievsa/autograder/) page for the Autograder also has testcase examples (under the `examples` directory).

As a quick example, if you want to test your `a-star` algorithm, you can go about it as follows.
1. In `tests/testcases`, create a file called `a-star.cpp`.
2. In `config.toml`, increase the total possible points by 25 (since the `a-star` algorithm is worth 25 points in this assignment).
Additionally, add "'a-star.cpp' = 0.25" to the `TESTCASE_WEIGHT` array.
3. Now in `a-star.cpp`, make sure you include any libraries needed to construct testcases. You also will want to add any struct declarations here to make your life easy, as well as forward declare your a-star algorithm (see `topological-sort.cpp` as an example).
4. Write test cases for your `a-star` algorithm. You can compute a score and divide it by a total score (as in the current test cases), or you can do a bunch of test cases and just call `PASS()` if they all pass, or `FAIL()` if they don't.
