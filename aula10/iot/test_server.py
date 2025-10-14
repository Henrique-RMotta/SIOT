from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')

def index():
    print(">> Página principal 'index.html' carregada pelo navegador.")
    return render_template('index.html')

@app.route('/control/<led_num>/<action>')
def control (led_num,action) :
    print("=" * 48)
    print(f"-Alvo: LED número {led_num}")
    print(f" -Ação: '{action}'")
    print("=" * 48)
    return f"Servidor de teste recebeu o comando: LED {led_num}, Ação'{action}'"

if __name__ == 'main': 
    app.run(debug=True,host='0.0.0.0',port=5000)