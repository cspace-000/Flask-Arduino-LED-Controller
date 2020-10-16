import flask
from flask import Flask, url_for, request, render_template, redirect
import serial
import time

app = Flask(__name__)


@app.route('/', methods=['GET', 'POST'])
def index():
	if request.method == 'POST':
		req = request.form
		#print(req)
		send_cmd(req)
		return redirect(request.url)
	return render_template('index.html')


def send_cmd(req):
	for v in req.values():
		bt = v.encode() 
		arduino.write(bt)
		time.sleep(.1)




if __name__ == '__main__':
	flask_port = 65432
	host = '0.0.0.0'

	arduino_port = 'COM5'
	baudrate = 9600

	arduino = serial.Serial(port=arduino_port, baudrate=baudrate, timeout=1)
	print('arduino connected')
	time.sleep(2)
	#arduino.write(b'B')
	#arduino.close()
	#app.run()

	app.run(host=host, port=flask_port)

