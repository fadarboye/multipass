/*
 * Copyright (C) Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_BASE_QEXCEPTION
#define MULTIPASS_BASE_QEXCEPTION

#include <QException>

#include <string>

namespace multipass
{
// CRTP template base class that is the boilerplate code of QException derived classes
// The usage of it should be CRTP derive class, that is inheriting the base calass and label itself final.
template <typename DerivedException>
class BaseQException : public QException
{
public:
    BaseQException(const std::string& err) : error_string{err}
    {
        // use concepts instead of static_assert to apply the contraint once C++ 20 arrives.
        static_assert(std::is_base_of_v<BaseQException, DerivedException>,
                      "DerivedException must be derived from BaseQException");
    }

    void raise() const override
    {
        throw static_cast<const DerivedException&>(*this);
    }

    BaseQException* clone() const override
    {
        return new DerivedException(static_cast<const DerivedException&>(*this));
    }

    const char* what() const noexcept override
    {
        return error_string.c_str();
    }

private:
    std::string error_string;
};
} // namespace multipass
#endif // MULTIPASS_BASE_QEXCEPTION
