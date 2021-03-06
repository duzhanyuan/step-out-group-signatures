/**
 * @file GetSignatureCommand.hpp
 * @author Pawel Kieliszczyk <pawel.kieliszczyk@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * Copyright (C) 2011 Pawel Kieliszczyk
 *
 * This file is part of Group Privacy.
 *
 * Group Privacy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Group Privacy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Group Privacy. If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * The file contains GetSignatureCommand class which is responsible
 * for interaction between a user and the system during
 * downloading a step-out group signature from the server.
 */

#ifndef GETSIGNATURECOMMAND_HPP
#define	GETSIGNATURECOMMAND_HPP

#include "../step_out_group_signatures/Signature.hpp"
#include "../step_out_group_signatures/StepOutGroupSignaturesClientManager.hpp"
#include "ICommand.hpp"

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include <string>

/**
 * GetSignatureCommand class.
 *
 * Implements ICommand interface. It is responsible
 * for interaction between a user and the system during
 * downloading a step-out group signature from the server.
 */
class GetSignatureCommand : public ICommand
{
public:
    /**
     * Constructor of the GetSignatureCommand class.
     *
     * Creates an instance of the class.
     *
     * @param socket Socket used to comunicate with the Group Privacy Server.
     */
    GetSignatureCommand(boost::shared_ptr<boost::asio::ip::tcp::socket> socket);

    /**
     * Supports a user during downloading a signature.
     */
    void execute();
private:
    /**
     * Takes a name of a file from standard input.
     *
     * @return Name of the file.
     */
    std::string determineSignatureFilename();

    /**
     * Gets from standard input a signature's number and returns it.
     *
     * @return Signature's ID.
     */
    unsigned int determineSignatureIndex();

    /**
     * Creates a file containing a given signature on the disk.
     *
     * @param filename Name of the file.
     * @param signature The step-out group signature.
     */
    void saveSignature(const std::string& filename, const Signature& signature);

    StepOutGroupSignaturesClientManager& stepOutGroupSignaturesClientManager; /**< Manager which implements scheme algorithms. */
};

#endif // GETSIGNATURECOMMAND_HPP
