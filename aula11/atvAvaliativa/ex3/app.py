from flask import Flask,render_template,jsonify
import serial
import time 

try:
    arduino = serial.Serial('COM4',9600,timeout=1)
    time.sleep(2)
except serial.SerialException as e:  
    print(f"Erro ao conectar com o Arduino {e}")
    arduino = None

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/getdata/')
def getVal():
    if not arduino:
        return jsonify({"erro": "Arduino não conectado"})

    if arduino.in_waiting > 0:
        time.sleep(1)
        linha = arduino.readline().decode('utf-8', errors='replace').strip()
        return jsonify({
                "value": linha[0]
        })
    else:
        return jsonify({"erro": "Nenhum dado disponível"})