# Images to film with ffmpeg
ffmpeg -r 30 -f image2 -s 1920x1080 -i ../recording/images/screenshot_%00d.png  -vcodec libx264 -crf 25  -pix_fmt yuv420p ../recording/disease-simulation.mp4