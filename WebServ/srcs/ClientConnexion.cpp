#include "../includes/ClientConnexion.hpp"

ClientConnexion::ClientConnexion(int fd, Server *server, State state) : _fd(fd), _server(server), _state(state), _bodySize(0) {
	_start = time(NULL);
	_timedOut = true;
}

ClientConnexion::~ClientConnexion() {
	_vec_char.clear();
}

State	ClientConnexion::getState() {
	return _state;
}

bool	ClientConnexion::hasTimedOut() {
	time_t now = time(NULL);
	if (now - _start > CLIENT_TIMEOUT)
		_timedOut = true;
	else
		_timedOut = false;
	return (_timedOut);
}

Server	*ClientConnexion::getServer() {
	return _server;
}

std::vector<char> ClientConnexion::getVecChar() {
	return _vec_char;
}
size_t	ClientConnexion::getBufferLen() {
	return _bufferLen;
}

bool	ClientConnexion::getKeep_alive() {
	return keep_alive;
}

void	ClientConnexion::setKeepAlive(bool kp) {
	keep_alive = kp;
}


std::string	&ClientConnexion::getBufferIn() {
	return bufferIn;
}

std::string	&ClientConnexion::getBufferOut() {
	return bufferOut;
}

void	ClientConnexion::setState(State state) {
	_state = state;
}

// void	ClientConnexion::setRequest(Request *request) {
// 	_request = request;
// }

void ClientConnexion::setBufferOut(std::string buff) {
	bufferOut = buff;
}

void	ClientConnexion::clearBuffer() {
	bufferIn.clear();
	bufferOut.clear();
	_bodySize = 0;
	_vec_char.clear();
}

void	ClientConnexion::UpdateActivity() {
	_start = time(NULL);
}

bool	ClientConnexion::checkChunked(size_t body_start)
{
	std::string buffer = bufferIn.substr(body_start);
	std::size_t pos = buffer.find("0\r\n");
	if (pos != std::string::npos)
	{
		std::string buffer2 = buffer.substr(pos);
		std::size_t pos = buffer2.find("\r\n\r\n");
		if (pos != std::string::npos) {
			//_binaryBuffer = _vec_char.data();
			_bufferLen = _vec_char.size();
			//print(_vec_char);
			return true ;
		}
	}
	return false ;
}

bool	ClientConnexion::checkContentLength(size_t pos, size_t body_start)
{
	if (!_bodySize) {
		std::istringstream str(bufferIn.substr(pos));
		str >> _bodySize;
	}

	if (bufferIn.size() - body_start < (unsigned int)_bodySize)
		return false ;
	//print(_vec_char);
	//_binaryBuffer = _vec_char.data();
	return true ;
}


bool	ClientConnexion::isDoneReading()
{
	std::size_t body_start = bufferIn.find("\r\n\r\n");
	if (body_start == std::string::npos)
		return false ;
	body_start += 4;
	if (bufferIn.size() >= 4 && bufferIn.substr(0, 4) == "GET ")
		return true ;
	if (bufferIn.size() >= 7 && bufferIn.substr(0, 7) == "DELETE ")
		return true ;

	std::size_t pos = bufferIn.find("Content-Length:");
	if (pos == std::string::npos)
		return (checkChunked(body_start));
	else
		return (checkContentLength(pos + 15, body_start));

	return false ;
}

bool	ClientConnexion::isDoneWriting()
{
	if (bufferOut.size() > 0)
		return false ;
	return true ;
}

void	ClientConnexion::removeFromBuffer(int bytesSent)
{
	bufferOut.erase(0, bytesSent);
	if (!isDoneWriting())
		_state = WRITING;
	else
		_state = DONE_WRITING;
}

void	ClientConnexion::appendToBuffer(char *buffer, int len)
{
	bufferIn.append(buffer, len); // pour gerer les txt
	_vec_char.insert(_vec_char.end(), buffer, buffer + len); // pour gerer les binaires
	if (!isDoneReading())
		_state = READING;
	else
		_state = DONE_READING;
}


