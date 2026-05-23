# ASCII Art Converter
Lightweight C++ utility that reads local `.bmp` images, calculates relative pixel luminance, and maps them directly to character densities.

The program automatically corrects for the typical $2:1$ vertical-to-horizontal proportions of terminal fonts, ensuring the output image remains unwarped.

<img width="494" height="396" alt="Screenshot From 2026-05-23 22-30-54" src="https://github.com/user-attachments/assets/6dc8d6f6-ae05-4aa6-85f3-03690ea6d455" />
<img width="367" height="396" alt="Screenshot From 2026-05-23 21-49-45" src="https://github.com/user-attachments/assets/7212260e-fc34-4ee3-b90d-1de8015f6288" />


## Image conversion
If you need to convert an image (like a PNG or JPG) into a compatible `.bmp` file, you can use this free online tool: [Online-Converting Image to BMP](https://online-converting.com/image/convert2bmp/).

When configuring your conversion options on the site, ensure you use the following settings to match the C++ parser requirements:
* **24-bit (RGB)**
* **Uncompressed**
* **Bottom-Up orientation**

## Build instruction in terminal
### Terminal
You can compile the project using any standard C++ compiler (such as `g++` or `clang++`).
Make sure your terminal session is currently running inside the main `ascii-art` project root folder so the relative file path for `media/input.bmp` resolves correctly.

Run the compilation command from your project root directory:

```bash
g++ -O3 src/main.cpp src/image.cpp -I ./include -o ascii_art
./ascii_art
```
### IDE
If you prefer running the project directly inside CLion or a similar IDE rather than the terminal, you can just open the project folder and use the built-in run button.

To prevent file-loading errors, make sure to change the Working directory in your IDE's **Run Configuration settings** from cmake-build-debug to your main ascii-art project root directory. This ensures the program can find your media/ folder automatically.
