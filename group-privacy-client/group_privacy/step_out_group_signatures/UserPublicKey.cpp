/**
 * @file UserPublicKey.cpp
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
 */

#include "UserPublicKey.hpp"

UserPublicKey::UserPublicKey() : gQm()
{
}

UserPublicKey::UserPublicKey(const PolynomialInTheExponent<SGS::QM_POLYNOMIAL_DEGREE>& gQmInit)
    : gQm(gQmInit)
{
}

UserPublicKey::UserPublicKey(const UserPublicKey& userPublicKey)
    : gQm(userPublicKey.gQm)
{
}

UserPublicKey& UserPublicKey::operator=(const UserPublicKey& userPublicKey)
{
    gQm = userPublicKey.gQm;
    return *this;
}

const PolynomialInTheExponent<SGS::QM_POLYNOMIAL_DEGREE>& UserPublicKey::getQm() const
{
    return gQm;
}

void UserPublicKey::setQm(const PolynomialInTheExponent<SGS::QM_POLYNOMIAL_DEGREE>& gQmInit)
{
    gQm = gQmInit;
}
