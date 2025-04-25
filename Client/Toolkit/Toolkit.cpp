#include "Toolkit.h"

void Toolkit::write_to_server(int socket, std::string &command) {
    int cmd = atoi(command.c_str());
    std::string msg;
    long length;
    int sentBytes;
    std::string sentMsg = command;
    switch (cmd) {
        case 1:
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 2:
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 3:
            std::cout << "Enter the station name: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 4:
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 5:
            std::cout << "Enter the station name: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 6:
            std::cout << "Enter the train ID: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            std::cout << "Enter the station name: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            std::cout << "Enter the delay: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 7:
            std::cout << "Enter the train ID: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            std::cout << "Enter the station name: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            std::cout << "Enter the delay: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 8:
            std::cout << "Enter the username: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            std::cout << "Enter the password: ";
            std::getline(std::cin, msg);
            sentMsg += " " + msg;
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 9:
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        case 10:
            length = sentMsg.length();
            length = htonl(length);
            sentBytes = send(socket, &length, sizeof(long), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            sentBytes = send(socket, sentMsg.c_str(), sentMsg.length(), 0);
            if (sentBytes == -1) {
                std::cout << "ERROR: Couldn't send message to server.\n";
            }
            break;
        default:
            std::cout << "ERROR: Invalid command.\n";
            break;
    }

}

void Toolkit::read_from_server(int socket, bool &connected) {
    std::string msg;
    long length;

    int sentBytes = read(socket, &length, sizeof(long));
    if (sentBytes < 0) {
        std::cout << "ERROR: Couldn't read message from server.\n";
        connected = false;
    } else if (sentBytes == 0) {
        connected = false;
    } else {
        length = ntohl(length);
        char *buffer = new char[length + 1];

        sentBytes = read(socket, buffer, length);
        if (sentBytes <= 0) {
            std::cout << "ERROR: Couldn't read message from server.\n";
            connected = false;
        }
        buffer[length] = '\0';
        msg = buffer;
        delete[] buffer;
        std::cout << msg << std::endl;
    }

}

void Toolkit::showCommands() {
    std::cout << "The command are: " << std::endl;
    std::cout << "1. get_trains_info" << std::endl;
    std::cout << "2. get_arrival_info" << std::endl;
    std::cout << "3. get_arrival_info [station]" << std::endl;
    std::cout << "4. get_departure_info " << std::endl;
    std::cout << "5. get_departure_info [station]" << std::endl;
    std::cout << "6. add_arrival_delay <ID> <station> <delay>" << std::endl;
    std::cout << "7. add_departure_delay <ID> <station> <delay>" << std::endl;
    std::cout << "8. login <username> <password>" << std::endl;
    std::cout << "9. logout" << std::endl;
    std::cout << "10. close" << std::endl << std::endl;
}