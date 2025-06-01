# 🎧 Impulse DAW

**Impulse** is a lightweight, modern digital audio workstation (DAW) with an intuitive interface. Inspired by Ableton Live, it combines a minimal visual design with essential features for recording, mixing, and editing audio/MIDI tracks.

---

## 🚀 Build Instructions

### 🔧 Requirements

- **Qt 6** (Widgets, Core, Gui, Multimedia, etc.)
- **CMake** >= 3.16
- **g++** or **clang++** with C++17 support
- Linux (primary development and testing environment)

### 🔨 How to Build

```bash
# Clone the repository
git clone https://github.com/GuskiGlobal/Impulse.git
cd Impulse

# Create a build folder
mkdir build && cd build

# Generate Makefiles
cmake ..

#Build
make

# Build using all cores
make -j$(nproc)

# Run
./Impulse
```

---

## 🧱 Project Structure

```
Impulse/
├── include/                # Header files (.h)
│   ├── core/               # Core logic (tracks, mixer, MIDI, effects, etc.)
│   └── gui/                # GUI components (panels, widgets)
├── src/                    # Implementation files (.cpp)
├── assets/                 # Icons, audio files, themes, presets
├── tests/                  # Unit and integration tests
├── CMakeLists.txt          # CMake build script
└── README.md               # This file
```

---

## 📦 Features (in progress)

- [x] Audio and MIDI track management
- [x] Ableton-style TrackView and MixerView
- [x] Per-channel effects
- [x] Volume, pan, mute, solo, and record controls
- [ ] Real-time audio recording
- [ ] VST/LV2 plugin support
- [ ] Project export
- [ ] Customizable themes via QSS

---

## 🤝 Contributing

1. Fork the repository
2. Create a new branch: `git checkout -b my-feature`
3. Commit your changes: `git commit -m 'Add my feature'`
4. Push the branch: `git push origin my-feature`
5. Open a Pull Request!

---

## 🧑‍💻 Author

Developed by [Guski](https://github.com/GuskiGlobal)


