#include <iostream>
#include <thread>
#include <string>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

class GameServer {
private:
    std::string host;
    int port;
    std::vector<std::pair<int, int>> player_positions;
    std::unordered_map<int, int> player_health;
    std::vector<std::pair<int, int>> zombie_positions;
    std::unordered_map<std::pair<int, int>, int> zombie_health;
    int player_health_init = 100;
    int zombie_health_init = 20;
    bool game_over = false;

public:
    GameServer(std::string host, int port) : host(host), port(port) {}

    void start() {
        // 服务器启动逻辑
    }

    void handle_client(int client_socket) {
        // 处理客户端逻辑
    }

    void move_player(int client_socket, std::string direction) {
        // 移动玩家逻辑
    }

    void attack_zombie(int client_socket) {
        // 攻击僵尸逻辑
    }

    void check_zombie_collision() {
        // 检查玩家与僵尸碰撞逻辑
    }

    void spawn_zombies() {
        // 生成僵尸逻辑
    }

    void send_inventory(int client_socket) {
        // 发送物品栏逻辑
    }

    void buy_weapon(int client_socket) {
        // 购买武器逻辑
    }
};

class GameClient {
private:
    std::string server_ip;
    int server_port;
    SOCKET client_socket;

public:
    GameClient(std::string ip, int port) : server_ip(ip), server_port(port), client_socket(INVALID_SOCKET) {}

    bool init() {
        // 初始化Winsock和连接服务器逻辑
    }

    void send_message(const std::string& message) {
        // 发送消息给服务器
    }

    std::string receive_message() {
        // 从服务器接收消息
    }

    void close_connection() {
        // 关闭连接逻辑
    }
};

int main() {
    std::string server_ip = "127.0.0.1";
    int server_port = 5555;

    GameClient client(server_ip, server_port);
    if (!client.init()) {
        return 1;
    }

    std::cout << "Connected to server." << std::endl;
    std::cout << "Type 'quit' to exit." << std::endl;

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        
        if (input == "quit") {
            break;
        }

        client.send_message(input);
        std::string received_message = client.receive_message();
        std::cout << "Received: " << received_message << std::endl;
    }

    client.close_connection();
    return 0;
}
