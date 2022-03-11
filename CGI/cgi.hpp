/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:32:54 by sel-fadi          #+#    #+#             */
/*   Updated: 2022/03/11 14:46:36 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <map>
#include <cstdlib>
#include <vector>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <istream>
#include <sys/types.h>
#include <signal.h>
#include <string>
#include <algorithm>
#include "../src/request/Request.hpp"
// #include "../src/response/response.hpp"
// #include "../src/config/LocationClass.hpp"

class cgi
{
	public:
		Request _request;
		std::string arg;
		std::string scriptType;

	public:
		cgi();
		~cgi();
		cgi( cgi const &obj );
		cgi& operator=( cgi const &rhs );

		void processing_cgi(Request request);
		void exec_script( std::string filename );
		void exec_scriptGET(int fd);
		// void script_output(int fd);
		
		std::string getDate();
		std::string getOsName();

		void setRequest(Request request);

		std::string	_generateTmp( int fd );

	private:
		std::string	_status;
		std::string	_location;
		size_t		_contentLength;
		std::string	_output;
		std::string	_tmp;
		std::string	_tmpOutputFileName;

	public:
		void	parseOutput( int fd );
		std::string	getContent( void ) const;
			
		void setEnv();
		void setHeader(const std::string &key, const std::string &value, bool end);
};
