# Contributing to BLESpam Library

> [日本語版](CONTRIBUTING_ja.md) | [English](CONTRIBUTING.md)

Thank you for your interest in contributing to the BLESpam library! This document provides guidelines for contributing.

## How to Contribute

### Reporting Bugs

If you find a bug, please create an issue on GitHub with:
- Clear description of the bug
- Steps to reproduce
- Expected behavior
- Actual behavior
- Your hardware (board model)
- Software versions (Arduino IDE, ESP32 board package)
- Code that demonstrates the issue

### Suggesting Features

Feature requests are welcome! Please create an issue with:
- Clear description of the feature
- Use case / why it's needed
- Proposed implementation (if you have ideas)

### Code Contributions

We welcome pull requests! Please follow these guidelines:

1. **Fork the repository**
   ```bash
   git clone https://github.com/YOUR_USERNAME/Bluetooth-LE-Spam-for-micon.git
   cd Bluetooth-LE-Spam-for-micon
   ```

2. **Create a feature branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make your changes**
   - Follow the existing code style
   - Add comments for complex logic
   - Update documentation if needed

4. **Test your changes**
   - Verify compilation on target platforms
   - Test on real hardware when possible
   - Run the validation script:
     ```bash
     cd BLESpamLibrary
     bash extras/validate_structure.sh
     ```

5. **Commit your changes**
   ```bash
   git add .
   git commit -m "Add feature: description of changes"
   ```

6. **Push and create pull request**
   ```bash
   git push origin feature/your-feature-name
   ```
   Then create a pull request on GitHub

## Code Style Guidelines

### C++ Code
- Use 4 spaces for indentation (no tabs)
- Opening braces on same line
- Clear variable names
- Comment complex algorithms

Example:
```cpp
void BLESpam::someFunction(uint8_t parameter) {
    // Comment explaining what this does
    if (parameter > 0) {
        doSomething();
    }
}
```

### Arduino Sketches
- Keep examples simple and well-commented
- Include description at the top
- Use Serial output for debugging
- Show one feature per example when possible

### Documentation
- Use clear, concise language
- Include code examples
- Keep README files up to date
- Add entries to CHANGELOG.md

## Areas for Contribution

We especially welcome contributions in these areas:

### 1. Platform Support
- nRF52 series implementation
- nRF Connect SDK support
- Zephyr RTOS support
- Other BLE-capable platforms

### 2. Features
- Additional device types and spam patterns
- Fast Pair extended support
- Lovespouse device support
- BLE scanner/detector functionality
- Web-based configuration interface
- Power management optimizations

### 3. Examples
- Advanced usage examples
- Platform-specific examples
- Real-world use case demonstrations

### 4. Documentation
- Video tutorials
- Wiring diagrams
- Troubleshooting guides
- Translations to other languages

### 5. Testing
- Unit tests
- Hardware compatibility testing
- Range and performance benchmarks

## Development Setup

### Required Software
- Arduino IDE 1.8.13+ or Arduino IDE 2.x
- ESP32 board support package
- Git for version control

### Recommended Tools
- PlatformIO (for advanced development)
- Visual Studio Code
- Serial monitor tool

### Testing Hardware
- ESP32 development board
- Target devices for testing (optional but recommended)

## Pull Request Process

1. Update the CHANGELOG.md with details of changes
2. Update documentation (README, examples) as needed
3. Ensure all examples compile successfully
4. Test on real hardware when possible
5. Request review from maintainers

## Code of Conduct

### Our Standards
- Be respectful and inclusive
- Accept constructive criticism
- Focus on what's best for the community
- Show empathy towards other contributors

### Unacceptable Behavior
- Harassment or discrimination
- Trolling or insulting comments
- Publishing others' private information
- Other unethical or unprofessional conduct

## Ethical Guidelines

This library is for educational and research purposes. Contributors must:

- Not encourage illegal use
- Include appropriate warnings and disclaimers
- Respect device security and privacy
- Follow responsible disclosure practices

## Questions?

If you have questions about contributing, please:
- Open a GitHub Discussion
- Comment on a relevant issue
- Join the Discord server (link in main README)

## License

By contributing, you agree that your contributions will be licensed under the GPL-3.0 License.

---

Thank you for contributing to BLESpam! 🎉
