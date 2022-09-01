/*
 * Copyright (C) 2022 Canonical, Ltd.
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

#ifndef MULTIPASS_STUB_MOUNT_HANDLER
#define MULTIPASS_STUB_MOUNT_HANDLER

#include <multipass/mount_handlers/mount_handler.h>

#include "stub_ssh_key_provider.h"

namespace multipass
{
namespace test
{
struct StubMountHandler : public MountHandler
{
    StubMountHandler() : MountHandler{key_provider}
    {
    }

    void init_mount(VirtualMachine* vm, const std::string& source_path, const std::string& target_path,
                    const id_mappings& gid_mappings, const id_mappings& uid_mappings) override
    {
    }

    void start_mount(VirtualMachine* vm, ServerVariant server, const std::string& target_path,
                     const std::chrono::milliseconds& timeout) override
    {
    }

    void stop_mount(const std::string& instance, const std::string& path) override
    {
    }

    void stop_all_mounts_for_instance(const std::string& instance) override
    {
    }

    bool has_instance_already_mounted(const std::string& instance, const std::string& path) const override
    {
        return false;
    }

    StubSSHKeyProvider key_provider;
};
} // namespace test
} // namespace multipass
#endif // MULTIPASS_STUB_MOUNT_HANDLER
