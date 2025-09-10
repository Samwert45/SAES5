from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/')
def hello():
    return jsonify({"message": "Hello Flask from CI/CD!", "status": "success"})

@app.route('/health')
def health():
    return jsonify({"status": "OK", "service": "Flask App"})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
