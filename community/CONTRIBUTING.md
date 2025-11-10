# Contributing to Aria Art Plotter

Thank you for your interest in contributing to the Aria Art Plotter project! This is a community-driven open source project, and we welcome contributions of all kinds.

## 🎯 Ways to Contribute

### 1. Build and Share
- Build your own Aria Art Plotter
- Share photos and videos of your build process
- Post artwork created with your plotter
- Tag @aria_art_plot on social media

### 2. Documentation
- Report unclear instructions
- Suggest documentation improvements
- Translate documentation to other languages
- Add tips and tricks you discovered
- Create additional tutorials

### 3. Design Improvements
- Submit modifications and enhancements
- Share alternative part designs
- Optimize existing components
- Create mounting options for new tools
- Design expansions (larger sizes, new features)

### 4. Software & Firmware
- Improve Klipper configurations
- Add new macros for artists
- Enhance the Arduino OLED code
- Create utility scripts
- Fix bugs

### 5. Testing & Feedback
- Report issues and bugs
- Test new features
- Provide feedback on usability
- Suggest new features

### 6. Community Support
- Answer questions in Discussions
- Help troubleshoot problems
- Share your expertise
- Welcome newcomers

---

## 📋 Before Contributing

### Review Existing Work
1. Check [Issues](https://github.com/gustavomayoral/aria_art_plot/issues) for existing reports
2. Browse [Discussions](https://github.com/gustavomayoral/aria_art_plot/discussions) for ongoing conversations
3. Review [Pull Requests](https://github.com/gustavomayoral/aria_art_plot/pulls) to avoid duplicating work

### Understand the Licenses
- **Hardware**: CERN-OHL-S-2.0 (strong reciprocal)
- **Documentation**: CC BY-SA 4.0
- **Software**: GPL-3.0 (for Klipper derivatives)

Your contributions will be licensed under these same terms.

---

## 🐛 Reporting Issues

### Bug Reports

When reporting a bug, please include:

**Title**: Clear, concise description
```
Example: "Z-axis homing fails after mesh compensation"
```

**Description should include**:
- **What you expected to happen**
- **What actually happened**
- **Steps to reproduce**
- **Your setup**: Plotter size, modifications, firmware version
- **Photos/videos** if relevant
- **Log files** if applicable

**Template**:
```markdown
## Description
Brief description of the issue

## Expected Behavior
What should happen

## Actual Behavior
What actually happens

## Steps to Reproduce
1. Step one
2. Step two
3. Step three

## System Information
- Plotter size: 20×20 / 30×30 / custom
- Modifications: List any changes from stock design
- Firmware version: Klipper version, commit hash
- Control board: Manta M5P V1.0 / other

## Additional Context
Logs, photos, videos, etc.
```

### Feature Requests

For new features:
- Clearly describe the feature
- Explain the use case and benefit
- Consider implementation complexity
- Discuss alternatives you've considered

---

## 🔧 Contributing Code/Design

### Getting Started

1. **Fork the repository**
   ```bash
   git clone https://github.com/YOUR-USERNAME/aria_art_plot.git
   cd aria_art_plot
   ```

2. **Create a branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```
   
   Branch naming:
   - `feature/` - New features
   - `fix/` - Bug fixes
   - `docs/` - Documentation updates
   - `refactor/` - Code refactoring

3. **Make your changes**
   - Follow existing code/design style
   - Test thoroughly
   - Document your changes

4. **Commit your changes**
   ```bash
   git add .
   git commit -m "Clear description of changes"
   ```
   
   Commit message format:
   ```
   Type: Brief description
   
   Longer description if needed explaining:
   - What changed
   - Why it changed
   - Any breaking changes
   ```
   
   Types: `feat`, `fix`, `docs`, `style`, `refactor`, `test`, `chore`

5. **Push to your fork**
   ```bash
   git push origin feature/your-feature-name
   ```

6. **Create a Pull Request**
   - Use the PR template
   - Link related issues
   - Add screenshots/videos if visual changes
   - Request review

### Code Standards

#### Python
- Follow PEP 8 style guide
- Include docstrings for functions
- Add comments for complex logic
- Test with multiple Python versions if possible

#### Klipper Config
- Follow Klipper documentation conventions
- Comment non-obvious settings
- Include explanatory header comments
- Test thoroughly before submitting

#### Arduino/C++
- Follow existing code style
- Use meaningful variable names
- Comment complex sections
- Verify compilation before submitting

### Design File Standards

#### STL Files
- Export in millimeters
- Ensure manifold (watertight) geometry
- Orient for optimal printing
- Include print settings in accompanying README
- Test print before submitting

#### DXF Files
- Export in millimeters
- Use consistent layer naming
- Include material specifications
- Note any required post-processing

#### CAD Source Files
- Include parametric source if possible
- Document design intent
- Note any dependencies or required plugins

---

## 📝 Contributing Documentation

### Documentation Guidelines

- **Clear and concise**: Use simple language
- **Well-organized**: Logical flow and structure
- **Visual aids**: Include photos, diagrams, videos when helpful
- **Tested**: Verify instructions work as written
- **Accessible**: Consider various skill levels

### Documentation Style

- Use present tense ("Connect the cable" not "Cable is connected")
- Use active voice ("Tighten the screw" not "The screw should be tightened")
- Number steps sequentially
- Bold important warnings
- Use code blocks for commands/code
- Include metric and imperial measurements where relevant

### Safety Notes

Always include safety warnings where relevant:
```markdown
⚠️ **WARNING**: Disconnect power before working on electronics!
```

---

## 🎨 Sharing Your Build

We love seeing your builds! Share them:

### On GitHub Discussions
1. Go to [Discussions](https://github.com/gustavomayoral/aria_art_plot/discussions)
2. Start a new discussion in "Show and Tell"
3. Include:
   - Photos of your build
   - Any modifications you made
   - Challenges you faced and solutions
   - Artwork you've created

### On Social Media
- Tag @aria_art_plot
- Use #AriaArtPlotter
- Share on X, Instagram, Threads
- Link back to this repository

### On Printables
- Upload your build to Printables
- Add it as a "Make" to the [Aria Art Plotter page](https://www.printables.com/@aria_art_3610199)
- Share your print settings

---

## 🏗️ Development Workflow

### For Significant Changes

1. **Discuss first**: Open an issue or discussion before major work
2. **Get feedback**: Ensure the change aligns with project goals
3. **Plan implementation**: Outline your approach
4. **Implement**: Make your changes
5. **Test extensively**: Verify nothing breaks
6. **Document**: Update relevant documentation
7. **Submit PR**: Request review

### Pull Request Process

1. **Update documentation**: If your change requires it
2. **Add to CHANGELOG**: Note your changes
3. **Test thoroughly**: Verify functionality
4. **Respond to feedback**: Address reviewer comments
5. **Maintain**: Be available for questions after merge

### Review Criteria

PRs will be evaluated on:
- **Functionality**: Does it work as intended?
- **Quality**: Is the code/design clean and maintainable?
- **Documentation**: Are changes documented?
- **Testing**: Has it been tested?
- **Compatibility**: Does it break existing builds?
- **Safety**: Are there any safety concerns?

---

## 🎓 Learning Resources

New to open source? Start here:
- [GitHub's Guide to Contributing](https://docs.github.com/en/get-started/quickstart/contributing-to-projects)
- [First Contributions Guide](https://github.com/firstcontributions/first-contributions)

New to 3D printing/CNC?
- [3D Printing Basics](https://www.youtube.com/@aria_art_plot) - Check our channel
- [Klipper Documentation](https://www.klipper3d.org/)
- [CNC Basics](https://www.youtube.com/@aria_art_plot)

---

## 💬 Communication

### Where to Ask Questions

- **General questions**: [GitHub Discussions](https://github.com/gustavomayoral/aria_art_plot/discussions)
- **Bug reports**: [GitHub Issues](https://github.com/gustavomayoral/aria_art_plot/issues)
- **Quick help**: Social media @aria_art_plot
- **Build updates**: Social media with #AriaArtPlotter

### Response Time

This is a community project maintained by volunteers. Please be patient:
- Simple questions: Usually within 48 hours
- Complex issues: May take longer
- Pull requests: Aim for review within 1 week

---

## 🏆 Recognition

Contributors are recognized in several ways:
- Listed in CONTRIBUTORS.md
- Mentioned in release notes
- Featured in community showcases
- Credit in documentation where applicable

Significant contributions may be featured on:
- Project website
- Social media
- YouTube channel
- Newsletter (coming soon)

---

## ⚖️ Code of Conduct

### Our Pledge

We are committed to providing a welcoming, friendly, and safe environment for everyone, regardless of:
- Experience level
- Gender identity and expression
- Sexual orientation
- Disability
- Personal appearance
- Body size
- Race or ethnicity
- Age
- Religion or lack thereof
- Nationality

### Expected Behavior

- **Be respectful**: Treat everyone with kindness and respect
- **Be constructive**: Offer helpful feedback and suggestions
- **Be collaborative**: Work together toward common goals
- **Be patient**: Remember everyone was a beginner once
- **Be inclusive**: Welcome newcomers and help them learn

### Unacceptable Behavior

- Harassment, intimidation, or discrimination
- Offensive comments or personal attacks
- Trolling or deliberately inflammatory remarks
- Publishing others' private information
- Any conduct that creates an unsafe environment

### Enforcement

Violations may result in:
1. Warning from maintainers
2. Temporary ban from project spaces
3. Permanent ban for repeated or severe violations

Report issues to: [your contact email]

---

## 📜 License Agreement

By contributing, you agree that:
- Hardware contributions are licensed under CERN-OHL-S-2.0
- Documentation contributions are licensed under CC BY-SA 4.0
- Software contributions are licensed under GPL-3.0
- You have the right to submit the contribution
- You grant the project the right to use your contribution

---

## 🙏 Thank You!

Every contribution, no matter how small, helps make the Aria Art Plotter better for everyone. Whether you're fixing a typo, answering a question, or designing a major improvement—thank you for being part of this community!

**Questions about contributing?** Open a discussion or reach out on social media!

---

*Let's build amazing art tools together! 🎨*