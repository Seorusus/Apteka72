/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document) {

    'use strict';

    // To understand behaviors, see https://drupal.org/node/756722#behaviors
    Drupal.behaviors.general = {
        attach: function (context, settings) {

            $(".commerce-add-to-cart .colorbox-inline").colorbox({
                width:"80%",
                height:"auto",
                onComplete:function(){ console.log('onComplete: colorbox has displayed the loaded content'); }
            });

            $("#block-sy-commerce-add-select-city a").removeAttr("href");

            $(".line-item-quantity-raw", context).wrap("<a href='/cart'></a>");

            $("#block-block-1 button", context).click(function () {
                $("#block-block-3", context).toggleClass("show");
            });

            $("#block-multiblock-1 > button", context).click(function () {
                $("#block-multiblock-1 .content", context).toggleClass("show");
            });

            $("#block-taxonomy-menu-block-1 .hamburger", context).click(function () {
                $("#block-taxonomy-menu-block-1 .menu-wrap", context).toggleClass("hide");
            });

            $("#block-multiblock-7 .hamburger", context).click(function () {
                $("#block-multiblock-7 .content", context).toggleClass("show");
            });

            $("#block-sy-commerce-add-select-city a", context).click(function () {
                $(this).toggleClass("active");
            });

            $("#block-sy-commerce-add-select-city a", context).first().click(function () {
                $("#block-block-3", context).toggleClass("show");
                $("#block-block-9", context).removeClass("show");
            });

            $("#block-sy-commerce-add-select-city a", context).last().click(function () {
                $("#block-block-9", context).toggleClass("show");
                $("#block-block-3", context).removeClass("show");
            });

            var forEach = function (t, o, r) {
                if ("[object Object]" === Object.prototype.toString.call(t))for (var c in t)Object.prototype.hasOwnProperty.call(t, c) && o.call(r, t[c], c, t); else for (var e = 0, l = t.length; l > e; e++)o.call(r, t[e], e, t)
            };

            var hamburgers = document.querySelectorAll(".hamburger");
            if (hamburgers.length > 0) {
                forEach(hamburgers, function (hamburger) {
                    hamburger.addEventListener("click", function () {
                        this.classList.toggle("is-active");
                    }, false);
                });
            }

            $(".view-catalog .view-content").justifiedGallery();

            $(".description > div", context).readmore({
                collapsedHeight: 160,
                speed: 100,
                moreLink: '<a href="#">Читать полностью</a>',
                lessLink: '<a href="#">Скрыть текст</a>',

                afterToggle: function (trigger, element, expanded) {
                    if (!expanded) { // The "Close" link was clicked
                        $('html, body').animate({scrollTop: element.offset().top}, {duration: 100});
                    }
                }

            });

            $(".commerce-line-item-actions").prepend("<a class='catalog-link' href='/catalog'>Продолжить покупки</a>");

            $("[name='search_block_form']").attr('placeholder', 'Поиск по сайту');


            $("#commerce-checkout-form-checkout label").each(function () {
                var labelText = $(this).text().replace(' *', '').toLowerCase();
                $(this).hide();
                //$(this).next().attr('placeholder', 'Введите ' + labelText);
            });

            $("#commerce-checkout-form-checkout .form-item").each(function () {
                if ($(this).children().hasClass("required")) {
                    $(this).addClass('required-row');
                }
            });


            $("#edit-customer-profile-billing-commerce-customer-address .name-block div").first().find('input').attr('placeholder', 'Введите имя');
            $("#edit-customer-profile-billing-commerce-customer-address .name-block div").last().find('input').attr('placeholder', 'Введите фамилию');
            $(".form-item-customer-profile-billing-commerce-customer-address-und-0-organisation-name").find('input').attr('placeholder', 'Введите организацию');
            $("#edit-customer-profile-billing-commerce-customer-address .street-block > div").first().find('input').attr('placeholder', 'Введите адрес');
            // $("#edit-customer-profile-billing-commerce-customer-address .street-block > div").last().hide();
            $("#edit-customer-profile-billing-commerce-customer-address .locality-block > div").first().find('input').attr('placeholder', 'Введите город');
            $("#edit-customer-profile-billing-commerce-customer-address .locality-block > div").last().find('input').attr('placeholder', 'Почтовый код');


        }
    };

})(jQuery, Drupal, this, this.document);
