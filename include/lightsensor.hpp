// Classe permettant de détecter la couleur du sol que capte un light sensor
class LightSensor {
    
    private:
        int port;
    
    public:
        LightSensor(int p_port);
        bool detect();
};
