## Irrlicht

The code is a fork  of Irrlicht trunk. Some new features are added, such as webrtc streamer and so on.

And now it can only be used on Ubuntu. 

### 1 Set Up

Before compile this repo, please install libraries related first.

```
sudo apt install libxxf86vm-dev
sudo apt install libgl1-mesa-dev libglu1-mesa-dev
sudo apt install libxext-dev
sudo apt install libxcursor-dev
sudo apt install libavcodec-dev libavformat-dev libswscale-dev libavutil-dev libavdevice-dev
```

In the root directory, 

```bash
cd source/Irrlicht
cmake -B build
cd build
make
```

Then, you can have fun. 

### 2 API Reference

TODO: add api reference.

### 3 TODO

- [ ] CMAKE : shared libraries and install operations are not added yet.
- [ ] WebGL: web client not added. (Maybe three.js)
- [ ] Examples: a normal example, and a cloud render example will be added soon.



### 4 Questions

So far, **the process is stuck on macOS**. The objective-c++ leads to lots of problems. CMake could not integrate C with Objective-c++.

So I have to use the XCode proj to process the program. However, the new added libdatachannel souce seems lead to a conflict,  "unknown typename uuid_t", and I cannot some reference about this problem. And the failed repo is [here](https://github.com/MagicAtom/irrlicht-ce.git).

But, our purpose is not to run this server on macOS, so we can just ignore this problem. If you have any ideas about the bug, just contract me songty404@gmail.com.

And for Windows users,**the repo source is proved having ability to compile on windows**, but I don't have a windows laptop and enough time. If you need any help on compiling engine on windows, just contract me.

**In short, I don't have time to fit my code on Windows and macOS, and also no money. And the revised engine is intended to be run on servers.**

