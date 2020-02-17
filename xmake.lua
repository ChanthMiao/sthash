
-- add modes: debug and release 
add_rules("mode.debug", "mode.release")

set_languages("c99")

set_warnings("all", "error")

set_targetdir("$(projectdir)/build")

if is_plat("windows") then
    add_cxflags("/source-charset: utf-8")
end

-- add target
target("sthash")

    set_kind("shared")

    if is_plat("linux") then
        add_cxflags("-fPIC")
    elseif is_plat("windows") then 
        add_ldflags("/DEF: DEF")
    end

    add_files("src/*.c")

    add_links("mbedtls", "mbedcrypto")

    set_default(true)

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
