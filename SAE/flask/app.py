from flask import Flask, jsonify, request

app = Flask(__name__)

# Données en mémoire pour test
users = [
    {"id": 1, "name": "John Doe", "email": "john@example.com"},
    {"id": 2, "name": "Jane Smith", "email": "jane@example.com"}
]

@app.route('/')
def hello():
    return jsonify({"message": "Hello Flask!"})

@app.route('/users', methods=['GET'])
def get_users():
    return jsonify(users)

@app.route('/users', methods=['POST'])
def create_user():
    data = request.get_json()
    new_user = {
        "id": len(users) + 1,
        "name": data['name'],
        "email": data['email']
    }
    users.append(new_user)
    return jsonify(new_user), 201

@app.route('/health')
def health():
    return jsonify({"status": "OK", "service": "Flask App"})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
