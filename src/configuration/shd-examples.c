/**
 * The Shadow Simulator
 *
 * Copyright (c) 2010-2011 Rob Jansen <jansen@cs.umn.edu>
 *
 * This file is part of Shadow.
 *
 * Shadow is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Shadow is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Shadow.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "shadow.h"

GString* example_getEchoExampleContents() {
	return g_string_new(
		"<plugin name=\"echoplugin\" path=\"libshadow-plugin-echo.so\" />"
		"<cdf name=\"echocpu\" center=\"100000000\" width=\"20000000\" tail=\"20000000\" />"
		"<cdf name=\"echobandwidth\" center=\"100\" width=\"0\" tail=\"0\" />"
		"<cdf name=\"echolatency\" center=\"200\" width=\"40\" tail=\"20\" />"
		"<network name=\"reliableechonetwork\" latency=\"echolatency\" reliability=\"1.0\" />"
		"<network name=\"unreliableechonetwork\" latency=\"echolatency\" reliability=\"0.5\" />"
		"<software name=\"echoudpserver\" plugin=\"echoplugin\" time=\"10\" arguments=\"udp server\" />"
		"<software name=\"reliableechoudpclient\" plugin=\"echoplugin\" time=\"20\" arguments=\"udp client reliable.udpserver.echo\" />"
		"<software name=\"echoudploopback\" plugin=\"echoplugin\" time=\"20\" arguments=\"udp loopback\" />"
		"<software name=\"echotcpserver\" plugin=\"echoplugin\" time=\"10\" arguments=\"tcp server\" />"
		"<software name=\"reliableechotcpclient\" plugin=\"echoplugin\" time=\"20\" arguments=\"tcp client reliable.tcpserver.echo\" />"
		"<software name=\"unreliableechotcpclient\" plugin=\"echoplugin\" time=\"20\" arguments=\"tcp client unreliable.tcpserver.echo\" />"
		"<software name=\"echotcploopback\" plugin=\"echoplugin\" time=\"20\" arguments=\"tcp loopback\" />"
		"<software name=\"echosocketpair\" plugin=\"echoplugin\" time=\"20\" arguments=\"tcp socketpair\" />"
		"<software name=\"echopipe\" plugin=\"echoplugin\" time=\"20\" arguments=\"pipe\" />"
		"<node name=\"reliable.udpserver.echo\" software=\"echoudpserver\" network=\"reliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"reliable.udpclient.echo\" software=\"reliableechoudpclient\" network=\"reliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"reliable.udploopback.echo\" software=\"echoudploopback\" network=\"reliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"reliable.tcpserver.echo\" software=\"echotcpserver\" network=\"reliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"reliable.tcpclient.echo\" software=\"reliableechotcpclient\" network=\"reliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"reliable.tcploopback.echo\" software=\"echotcploopback\" network=\"reliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"unreliable.tcpserver.echo\" software=\"echotcpserver\" network=\"unreliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"unreliable.tcpclient.echo\" software=\"unreliableechotcpclient\" network=\"unreliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"unreliable.tcploopback.echo\" software=\"echotcploopback\" network=\"unreliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"socketpair.echo\" software=\"echosocketpair\" network=\"reliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<node name=\"pipe.echo\" software=\"echopipe\" network=\"reliableechonetwork\" bandwidthup=\"echobandwidth\" bandwidthdown=\"echobandwidth\" cpu=\"echocpu\" />"
		"<kill time=\"180\" />");
}

GString* example_getFileExampleContents() {
	/* serve and download /bin/ls 10 times for each of 100 clients */
	return g_string_new(
		"<plugin name=\"filetransfer\" path=\"libshadow-plugin-filetransfer.so\" />"
		"<cdf name=\"filecpu\" center=\"100000000\" width=\"20000000\" tail=\"20000000\" />"
		"<cdf name=\"serverbandwidth\" center=\"10240\" width=\"0\" tail=\"0\" />"
		"<cdf name=\"clientbandwidth\" center=\"1024\" width=\"0\" tail=\"0\" />"
		"<cdf name=\"filelatency\" center=\"100\" width=\"20\" tail=\"20\" />"
		"<network name=\"filenetwork\" latency=\"filelatency\" reliability=\"1.0\" />"
		"<software name=\"fileserver\" plugin=\"filetransfer\" time=\"10\" arguments=\"server 8080 /bin/\" />"
		"<software name=\"fileclient\" plugin=\"filetransfer\" time=\"20\" arguments=\"client single server.filetransfer 8080 none 0 10 /ls\" />"
		"<node name=\"server.filetransfer\" software=\"fileserver\" network=\"filenetwork\" bandwidthup=\"serverbandwidth\" bandwidthdown=\"serverbandwidth\" cpu=\"filecpu\" />"
		"<node name=\"client.filetransfer\" quantity=\"100\" software=\"fileclient\" network=\"filenetwork\" bandwidthup=\"clientbandwidth\" bandwidthdown=\"clientbandwidth\" cpu=\"filecpu\" />"
		"<kill time=\"600\" />");
}
