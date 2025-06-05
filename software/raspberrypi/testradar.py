import numpy as np
import time
from acconeer.exptool import a121
from acconeer.exptool.algo import distance

# Create and connect the client
client = a121.Client.open(serial_port="/dev/ttyUSB0")
print("Client opened successfully.")

# Create distance detector and config
detector_config = distance.DetectorConfig(
    start_m=0.25,
    end_m=3.0,
    max_profile=a121.Profile.PROFILE_5,
    threshold_method=distance.ThresholdMethod.CFAR,
    peaksorting_method=distance.PeakSortingMethod.STRONGEST,
    threshold_sensitivity=0.5,
    update_rate=50.0,  # in Hz
)

detector = distance.Detector(client=client, detector_config=detector_config)
metadata = detector.setup()
print("Distance detector configured successfully.")

# Start session
detector.start()
print("Session started.")

try:
    while True:
        result = detector.get_next()
        if result is not None and result.peaks:
            for i, peak in enumerate(result.peaks):
                print(f"Peak {i+1}: {peak:.2f} m")
        else:
            print("No peaks detected.")
        time.sleep(0.02)  # Match update_rate ~50Hz
except KeyboardInterrupt:
    print("Session interrupted.")
    detector.stop()
    client.close()
    print("Session stopped and client closed.")