import cv2
import os
import sys


if len(sys.argv) < 2:
    print("USAGE: python3" + sys.argv[0] + " [video file]")
    exit()

video_path = sys.argv[1]
video_file_name = os.path.splitext(video_path)[0]

cap = cv2.VideoCapture(video_path)

if not cap.isOpened():
    print("Error opening the video file")
    exit()

# Crear una carpeta para guardar los frames
output_folder = video_file_name
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

frame_count = 0

# Leer el video frame por frame
while True:
    ret, frame = cap.read()
    
    if not ret:
        break
    
    # Guardar cada frame como una imagen en formato BMP (sin compresión)
    frame_filename = f"{output_folder}/frame{frame_count:04d}.bin"
    # Abrir un archivo binario para escritura
    with open(frame_filename, "wb") as output_file:
        # Iterar sobre cada píxel de la imagen
        for y in range(frame.shape[0]):  # filas
            for x in range(frame.shape[1]):  # columnas
                # Obtener el píxel (BGR)
                pixel = frame[y, x]
                # Escribir los componentes del píxel en el archivo
                output_file.write(pixel.tobytes())  # BGR
    frame_count += 1

# Liberar los recursos
cap.release()
print(f"Frames saved to: {output_folder}")
