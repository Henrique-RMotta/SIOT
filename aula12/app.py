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

@app.route('/control/<led_num>/<action>')
def control (led_num,action):
    if arduino:
        command = ''
        if led_num == '1':
            command = 'A' if action == 'on' else 'a'
        if command:
            arduino.write(command.encode())
            return f"Comando '{command}' enviado para o LED {led_num}"
        else:
            return "Comando Inválido"
    else:
        return "Arduino não conectado"
    
@app.route('/get_data/')
def buscarDadosSensor():
    if not arduino:
        return jsonify({"error": "Arduino não conectado"})

    command = 'T'
    arduino.write(command.encode())
    if arduino.in_waiting > 0:
        time.sleep(1)
        linha = arduino.readline().decode('utf-8', errors='replace').strip()
        values = linha.split(";")

        if len(values) >= 3:
            return jsonify({
                "temp": values[0],
                "umid": values[1],
                "lum" : values[2]
            })
        else:
            return jsonify({"error": f"Dado inválido: {linha}"})
    else:
        return jsonify({"error": "Nenhum dado disponível"})

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader = False)