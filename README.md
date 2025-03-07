# 🖼️ Image and Video Processing with OpenCV  

## 📖 Overview  

This project demonstrates fundamental **image and video processing** techniques using **OpenCV** in C++. The goal is to apply key **computer vision operations** such as **image rotation, resizing, blurring, and motion detection** in video streams.  

### 🔹 **Key Features:**  
✅ **Image Rotation & Resizing** – Rotates an image **30 degrees counterclockwise** and resizes it while maintaining aspect ratio.  
✅ **Gaussian Blur Effect** – Applies a **strong Gaussian filter** to blur the image.  
✅ **Motion Detection in Video** – Captures a live video feed, calculates **frame differences**, and saves the processed output.  

---

## 📂 Project Structure  

📁 Image-and-Video-Processing-OpenCV
├── 📂 images/ # Input/output images
│ ├── original_kitty.jpg # Original input image
│ ├── resized_kitty.jpg # Rotated and resized image
│ ├── blurred_kitty.jpg # Blurred image
├── 📂 src/ # Source code files
│ ├── image_resize_rotate.cpp # Image rotation and resizing
│ ├── image_blur.cpp # Image blurring
│ ├── video_motion_detection.cpp # Motion detection in video
├── 📂 results/ # Output files
│ ├── output.avi # Processed video output

