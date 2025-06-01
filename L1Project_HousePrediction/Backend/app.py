from flask import Flask, request, jsonify
from flask_cors import CORS


app = Flask(__name__)
CORS(app)  # Enable CORS so your frontend can communicate with backend

@app.route('/predict', methods=['POST'])
def predict():
    data = request.get_json()
    
    # For now, just print to console to see what we get
    print("Received data:", data)
    
    # Dummy prediction: just add bedrooms * 100000 + bathrooms * 50000 + living_area * 2000
    bedrooms = data.get('bedrooms', 0)
    bathrooms = data.get('bathrooms', 0)
    living_area = data.get('living_area', 0)
    
    predicted_price = bedrooms * 100000 + bathrooms * 50000 + living_area * 2000
    
    return jsonify({"predicted_price": predicted_price})

@app.route('/')
def home():
    return "Flask backend is running!"

if __name__ == '__main__':
    app.run(debug=True)
