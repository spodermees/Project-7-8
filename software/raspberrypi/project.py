import numpy as np
from acconeer.exptool import a121
import time


print("Starting Acconeer A121 radar session...")

client = a121.Client.open(serial_port="/dev/ttyUSB0")

print("Client opened successfully.")

# Set up sensor config correctly
sensor_config = a121.SensorConfig()
sensor_config.profile = a121.Profile.PROFILE_3
sensor_config.step_length = 2
sensor_config.num_points = 100
sensor_config.hwaas = 16
sensor_config.sweeps_per_frame = 8

client.setup_session(sensor_config)

print("Session configured successfully.")

client.start_session()
try: 
    while True:
        # Get one frame of data
        result = client.get_next()
        frame = result.frame  # shape: (sweeps_per_frame, num_points)
        averaged = np.mean(frame, axis=0)

        peak_idx = np.argmax(averaged)

        step_m = sensor_config.step_length * 0.005
        distance_m = peak_idx * step_m

        print(f"Measured distance: {distance_m:.2f} m")
        time.sleep(0.1)
except KeyboardInterrupt:
    print("Session interrupted by user.")
    client.stop_session()
    client.close()

