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

            $(".line-item-quantity-raw", context).wrap("<a href='/cart'></a>");

            $("#block-block-1 button", context).click(function () {
                $("#block-block-3", context).toggleClass("show");
            });

            $("#block-taxonomy-menu-block-1 .hamburger", context).click(function () {
                $("#block-taxonomy-menu-block-1 .menu-wrap", context).toggleClass("hide");
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

            $("#commerce-checkout-form-checkout td").attr('valign', 'center');

        }
    };

})(jQuery, Drupal, this, this.document);
