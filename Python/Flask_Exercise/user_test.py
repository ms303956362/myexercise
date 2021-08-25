import requests
import os
import base64
from PIL import Image
from io import BytesIO


out_dir = './'

img_path = '10kV华深线#157杆 (18).JPG'
img = Image.open(img_path)
img_buffer = BytesIO()
img.save(img_buffer, format='JPEG')
byte_data = img_buffer.getvalue()
base64_str = str(base64.b64encode(byte_data), encoding='utf-8')

res = requests.get('http://10.15.194.44:12345', json={'img': base64_str}).json()
# res = requests.post('http://10.15.194.44:12345', json={'img': base64_str}).json()

byte_data = base64.b64decode(res['img_with_boxes'].encode('utf-8'))
img_buffer = BytesIO(byte_data)
img = Image.open(img_buffer)

img_file_name = 'out_' + img_path.split('/')[-1]
img_path = os.path.join(out_dir, img_file_name)
img.save(img_path)
print(res['objs'])
print(res['defect_info'])
