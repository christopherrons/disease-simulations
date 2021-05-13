# Images to film with ffmpeg
ffmpeg -framerate 30 -i recording/images/screenshot_%00d.png -c:v libx264 -profile:v high -crf 20 -pix_fmt yuv420p recording/disease-simulation.mp4